#include "own.h"

#define KJ_RS_DEFINE_OWN_DROP(symbol, type)                                                        \
  static_assert(sizeof(kj::Own<type>) == 2 * sizeof(void*), "unexpected kj::Own layout");          \
  void symbol(kj::Own<type>* own) {                                                                \
    own->~Own();                                                                                   \
  }

extern "C" {
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$bool$drop, bool)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$u8$drop, uint8_t)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$u16$drop, uint16_t)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$u32$drop, uint32_t)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$u64$drop, uint64_t)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$usize$drop, rust::usize)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$i8$drop, int8_t)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$i16$drop, int16_t)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$i32$drop, int32_t)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$i64$drop, int64_t)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$isize$drop, rust::isize)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$f32$drop, float)
KJ_RS_DEFINE_OWN_DROP(cxxbridge$kjrs$own$f64$drop, double)
}

#undef KJ_RS_DEFINE_OWN_DROP
