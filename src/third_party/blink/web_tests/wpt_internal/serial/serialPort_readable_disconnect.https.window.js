// META: script=/resources/testharness.js
// META: script=/resources/testharnessreport.js
// META: script=/gen/layout_test_data/mojo/public/js/mojo_bindings.js
// META: script=/gen/mojo/public/mojom/base/unguessable_token.mojom.js
// META: script=/gen/third_party/blink/public/mojom/serial/serial.mojom.js
// META: script=resources/serial-test-utils.js

serial_test(async (t, fake) => {
  const { port, fakePort } = await getFakeSerialPort(fake);
  // Select a buffer size smaller than the amount of data transferred.
  await port.open({ baudrate: 9600, buffersize: 64 });

  const data = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
  fakePort.write(data);
  fakePort.simulateDisconnectOnRead();

  const reader = port.readable.getReader();
  const { value, done } = await reader.read();
  assert_false(done);
  compareArrays(data, value);

  await promise_rejects_dom(t, 'NetworkError', reader.read());
  assert_equals(port.readable, null);

  await port.close();
}, 'Disconnect error closes readable and sets it to null');
