/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "ExternalTexture.h"

#ifdef XP_WIN
#  include "mozilla/webgpu/ExternalTextureD3D11.h"
#endif

namespace mozilla::webgpu {

// static
UniquePtr<ExternalTexture> ExternalTexture::Create(
    const uint32_t aWidth, const uint32_t aHeight,
    const struct ffi::WGPUTextureFormat aFormat) {
  UniquePtr<ExternalTexture> texture;
#ifdef XP_WIN
  texture = ExternalTextureD3D11::Create(aWidth, aHeight, aFormat);
#endif
  return texture;
}

ExternalTexture::ExternalTexture(const uint32_t aWidth, const uint32_t aHeight,
                                 const struct ffi::WGPUTextureFormat aFormat)
    : mWidth(aWidth), mHeight(aHeight), mFormat(aFormat) {}

ExternalTexture::~ExternalTexture() {}

}  // namespace mozilla::webgpu
