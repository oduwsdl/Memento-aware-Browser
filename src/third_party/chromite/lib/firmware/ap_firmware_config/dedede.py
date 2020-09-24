# -*- coding: utf-8 -*-
# Copyright 2020 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Dedede configs."""

from __future__ import print_function

_COMMON_PACKAGES = (
    'chromeos-ec',
    'coreboot',
    'depthcharge',
    'libpayload',
    'vboot_reference',
)

BUILD_WORKON_PACKAGES = _COMMON_PACKAGES + (
    'coreboot-private-files-baseboard-dedede',
)

BUILD_PACKAGES = _COMMON_PACKAGES + (
    'chromeos-bootimage',
    'coreboot-private-files',
    'intel-jslfsp',
)


def get_commands(servo):
  """Get specific flash commands for Dedede

  Each board needs specific commands including the voltage for Vref, to turn
  on and turn off the SPI flash. The get_*_commands() functions provide a
  board-specific set of commands for these tasks. The voltage for this board
  needs to be set to 3.3 V.

  Args:
    servo (servo_lib.Servo): The servo connected to the target DUT.

  Returns:
    list: [dut_control_on, dut_control_off, flashrom_cmd, futility_cmd]
      dut_control*=2d arrays formmated like [["cmd1", "arg1", "arg2"],
                                             ["cmd2", "arg3", "arg4"]]
                   where cmd1 will be run before cmd2
      flashrom_cmd=command to flash via flashrom
      futility_cmd=command to flash via futility
  """
  dut_control_on = []
  dut_control_off = []

  # Common flashing sequence for C2D2 and CCD
  # Shutdown AP so that it enters G3 state.
  dut_control_on.append(['ec_uart_cmd:apshutdown'])
  # Sleep to ensure the SoC rails get chance to discharge enough.
  dut_control_on.append(['sleep:5'])
  # Turn on the S5 rails & initiate partial power up.
  dut_control_on.append(['ec_uart_cmd:gpioset en_pp3300_a 1'])
  # Sleep to ensure the required delay for device power sequencing.
  # Require 130 ms between EN_PP3300_A assertion and EC_AP_RSMRST_L assertion.
  dut_control_on.append(['sleep:0.2'])
  # Halt the power sequencing by de-asserting EC_AP_RSMRST_L.
  dut_control_on.append(['ec_uart_cmd:gpioset ec_ap_rsmrst_l 0'])
  # De-assert again to be on the safe side.
  dut_control_on.append(['ec_uart_cmd:gpioset ec_ap_rsmrst_l 0'])

  if servo.is_c2d2:
    dut_control_on.append(['ap_flash_select:on'])
    dut_control_on.append(['spi2_vref:pp3300'])
    dut_control_off.append(['spi2_vref:off'])
    dut_control_off.append(['ap_flash_select:off'])
    programmer = 'raiden_debug_spi:serial=%s' % servo.serial
  elif servo.is_ccd:
    programmer = 'raiden_debug_spi:target=AP,serial=%s' % servo.serial
  else:
    raise Exception('%s not supported' % servo.version)

  flashrom_cmd = ['flashrom', '-p', programmer, '-w']
  futility_cmd = ['futility', 'update', '-p', programmer, '-i']

  return [dut_control_on, dut_control_off, flashrom_cmd, futility_cmd]
