// META: script=/resources/testharness.js
// META: script=/resources/testharnessreport.js
// META: script=/gen/layout_test_data/mojo/public/js/mojo_bindings.js
// META: script=/gen/mojo/public/mojom/base/unguessable_token.mojom.js
// META: script=/gen/third_party/blink/public/mojom/serial/serial.mojom.js
// META: script=resources/serial-test-utils.js

serial_test(async (t, fake) => {
  const { port, fakePort } = await getFakeSerialPort(fake);

  assert_equals(port.writable, null);

  await port.open({ baudrate: 9600 });
  const writable = port.writable;
  assert_true(writable instanceof WritableStream);

  await port.close();
  assert_equals(port.writable, null);

  const writer = writable.getWriter();
  const data = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
  await promise_rejects_dom(t, 'InvalidStateError', writer.write(data));
}, 'open() and close() set and unset SerialPort.writable');

serial_test(async (t, fake) => {
  const { port, fakePort } = await getFakeSerialPort(fake);

  await port.open({ baudrate: 9600 });
  assert_true(port.writable instanceof WritableStream);

  const writer = port.writable.getWriter();
  await promise_rejects_js(t, TypeError, port.close());

  writer.releaseLock();
  await port.close();
  assert_equals(port.writable, null);
}, 'Port cannot be closed while writable is locked');

serial_test(async (t, fake) => {
  const { port, fakePort } = await getFakeSerialPort(fake);

  await port.open({ baudrate: 9600 });
  assert_true(port.writable instanceof WritableStream);

  const writer = port.writable.getWriter();
  const data = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
  let writePromise = writer.write(data);
  writer.close();
  let { value, done } = await fakePort.read();
  await writePromise;
  compareArrays(value, data);

  await port.close();
  assert_equals(port.writable, null);
}, 'Can write a small amount of data');

serial_test(async (t, fake) => {
  const { port, fakePort } = await getFakeSerialPort(fake);
  // Select a buffer size smaller than the amount of data transferred.
  await port.open({ baudrate: 9600, buffersize: 64 });

  const writer = port.writable.getWriter();
  const data = new Uint8Array(1024);  // Much larger than buffersize above.
  for (let i = 0; i < data.byteLength; ++i)
    data[i] = i & 0xff;
  writer.write(data);
  writer.close();

  const reader = fakePort.readable_.getReader();
  const value = await readWithLength(reader, data.byteLength);
  reader.releaseLock();
  compareArrays(data, value);

  await port.close();
}, 'Can read a large amount of data');

serial_test(async (t, fake) => {
  const { port, fakePort } = await getFakeSerialPort(fake);
  await port.open({ baudrate: 9600 });

  const writable = port.writable;
  assert_true(writable instanceof WritableStream);
  let writer = writable.getWriter();

  fakePort.simulateSystemErrorOnWrite();
  const data = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
  await promise_rejects_dom(t, 'UnknownError', writer.write(data));

  assert_true(port.writable instanceof WritableStream);
  assert_not_equals(port.writable, writable);

  writer = port.writable.getWriter();
  let writePromise = writer.write(data);
  writer.close();
  await fakePort.waitForWriteErrorCleared();
  let { value, done } = await fakePort.read();
  await writePromise;
  compareArrays(value, data);

  await port.close();
  assert_equals(port.writable, null);
}, 'System error closes writable and replaces it with a new stream');

serial_test(async (t, fake) => {
  const { port, fakePort } = await getFakeSerialPort(fake);
  await port.open({ baudrate: 9600 });

  assert_true(port.writable instanceof WritableStream);
  const writer = port.writable.getWriter();

  fakePort.simulateDisconnectOnWrite();
  const data = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
  await promise_rejects_dom(t, 'NetworkError', writer.write(data));
  assert_equals(port.writable, null);

  await port.close();
}, 'Disconnect error closes writable and sets it to null');

serial_test(async (t, fake) => {
  const { port, fakePort } = await getFakeSerialPort(fake);

  await port.open({ baudrate: 9600 });
  assert_true(port.writable instanceof WritableStream);

  const encoder = new TextEncoderStream();
  const streamClosed = encoder.readable.pipeTo(port.writable);
  const writer = encoder.writable.getWriter();
  const writePromise = writer.write("Hello world!");
  const { value, done } = await fakePort.read();
  await writePromise;
  assert_equals("Hello world!", new TextDecoder().decode(value));
  await writer.close();
  await streamClosed;

  await port.close();
  assert_equals(port.writable, null);
}, 'Can pipe a stream to writable');

serial_test(async (t, fake) => {
  const { port, fakePort } = await getFakeSerialPort(fake);

  await port.open({ baudrate: 9600 });
  assert_true(port.writable instanceof WritableStream);

  const transform = new TransformStream();
  const readable = transform.readable.pipeThrough(new TextEncoderStream())
                                     .pipeThrough(new TransformStream())
                                     .pipeThrough(new TransformStream())
                                     .pipeThrough(new TransformStream());
  const streamClosed = readable.pipeTo(port.writable);
  const writer = transform.writable.getWriter();
  const writePromise = writer.write("Hello world!");
  const { value, done } = await fakePort.read();
  await writePromise;
  assert_equals("Hello world!", new TextDecoder().decode(value));
  await writer.close();
  await streamClosed;

  await port.close();
  assert_equals(port.writable, null);
}, 'Stream closure is observable through a long chain of transformers');
