#pragma once

#include <rust/cxx.h>

#include <kj/memory.h>

#include <cstdint>

// Drop functions for the `kj::Own<T>` of primitive `T` that a bridge accepts. Rust calls one from
// `KjOwn<T>::drop` through `kj_rs::OwnTarget`; a bridge generates the same function for each
// `extern "C++"` type it holds in a `KjOwn`.
extern "C" {
void cxxbridge$kjrs$own$bool$drop(kj::Own<bool>* own);
void cxxbridge$kjrs$own$u8$drop(kj::Own<uint8_t>* own);
void cxxbridge$kjrs$own$u16$drop(kj::Own<uint16_t>* own);
void cxxbridge$kjrs$own$u32$drop(kj::Own<uint32_t>* own);
void cxxbridge$kjrs$own$u64$drop(kj::Own<uint64_t>* own);
void cxxbridge$kjrs$own$usize$drop(kj::Own<rust::usize>* own);
void cxxbridge$kjrs$own$i8$drop(kj::Own<int8_t>* own);
void cxxbridge$kjrs$own$i16$drop(kj::Own<int16_t>* own);
void cxxbridge$kjrs$own$i32$drop(kj::Own<int32_t>* own);
void cxxbridge$kjrs$own$i64$drop(kj::Own<int64_t>* own);
void cxxbridge$kjrs$own$isize$drop(kj::Own<rust::isize>* own);
void cxxbridge$kjrs$own$f32$drop(kj::Own<float>* own);
void cxxbridge$kjrs$own$f64$drop(kj::Own<double>* own);
}
