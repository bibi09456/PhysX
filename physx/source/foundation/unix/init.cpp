#ifdef __cplusplus
extern "C" {
#endif

// Function with compiler attributes to prevent stripping
__attribute__((used, noinline, section(".text.init")))
void _dummy_init_impl() {
    // Volatile assembly to prevent optimization removal
    asm volatile("");
}

// Force reference in .init_array section
__attribute__((used, section(".init_array")))
void (*_dummy_init_ref)() = _dummy_init_impl;

#ifdef __cplusplus
}
#endif
