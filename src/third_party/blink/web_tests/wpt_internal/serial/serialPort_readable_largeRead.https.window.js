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

  const data = new Uint8Array(1024);  // Much larger than buffersize above.
  for (let i = 0; i < data.byteLength; ++i)
    data[i] = i & 0xff;
  fakePort.write(data);

  const reader = port.readable.getReader();
  const value = await readWithLength(reader, data.byteLength);
  compareArrays(data, value);
  reader.releaseLock();

  await port.close();
}, 'Can read a large amount of data');
