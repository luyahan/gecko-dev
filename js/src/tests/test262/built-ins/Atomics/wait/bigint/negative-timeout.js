// |reftest| skip-if(!xulRuntime.shell||!this.hasOwnProperty('Atomics')||!this.hasOwnProperty('SharedArrayBuffer')||(this.hasOwnProperty('getBuildConfiguration')&&getBuildConfiguration("arm64-simulator"))) -- browser cannot block main thread, Atomics,SharedArrayBuffer is not enabled unconditionally, ARM64 Simulator cannot emulate atomics
// Copyright (C) 2018 Rick Waldron. All rights reserved.
// This code is governed by the BSD license found in the LICENSE file.

/*---
esid: sec-atomics.wait
description: >
  Test that Atomics.wait times out with a negative timeout
features: [Atomics, BigInt, SharedArrayBuffer, TypedArray]
flags: [CanBlockIsTrue]
---*/

const i64a = new BigInt64Array(
  new SharedArrayBuffer(BigInt64Array.BYTES_PER_ELEMENT * 4)
);

assert.sameValue(
  Atomics.wait(i64a, 0, 0n, -1),
  "timed-out",
  'Atomics.wait(i64a, 0, 0n, -1) returns "timed-out"'
);

reportCompare(0, 0);
