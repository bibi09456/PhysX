#include "../common/WebIdlBindings.h"
#include "omnipvd/PxOmniPvd.h"
#include "OmniPvdWriter.h"
#include "OmniPvdFileWriteStream.h"
#include "CudaBindings.h"

#include "../common/VhacdBindings.h"

#include "PhysXJniGlue.h"

#if PX_ANDROID
extern "C" {
extern int __llvm_profile_write_file(void);
}

void __attribute__((destructor)) write_profile_on_exit(void) {
    __llvm_profile_write_file();
}
#endif

// nothing else to do here, the magic happens inside PhysXJniGlue.h
