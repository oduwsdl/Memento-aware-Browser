// META: script=/resources/testharness.js
// META: script=/resources/testharnessreport.js
// META: script=/gen/layout_test_data/mojo/public/js/mojo_bindings.js
// META: script=/gen/mojo/public/mojom/base/unguessable_token.mojom.js
// META: script=/gen/third_party/blink/public/mojom/serial/serial.mojom.js
// META: script=resources/serial-test-utils.js

serial_test(async (t, fake) => {
  const { port, fakePort } = await getFakeSerialPort(fake);
  // Select a buffer size larger than the amount of data transferred.
  await port.open({ baudrate: 9600, buffersize: 64 });

  fakePort.write(new TextEncoder().encode("Hello world!"));

  const decoder = new TextDecoderStream();
  const streamClosed = port.readable.pipeTo(decoder.writable);
  const reader = decoder.readable.getReader();
  const { value, done } = await reader.read();
  assert_false(done);
  assert_equals("Hello world!", value);
  await reader.cancel();
  await streamClosed.catch(reason => {
    assert_equals(undefined, reason);
  });

  await port.close();
}, 'Can pipe readable through a transform stream.')
