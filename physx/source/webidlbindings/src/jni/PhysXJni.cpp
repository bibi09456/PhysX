#include "../common/WebIdlBindings.h"
#include "omnipvd/PxOmniPvd.h"
#include "OmniPvdWriter.h"
#include "OmniPvdFileWriteStream.h"
#include "CudaBindings.h"

#include "../common/VhacdBindings.h"

#include "PhysXJniGlue.h"

#if PX_ANDROID
#include <signal.h>
extern "C" {
extern int __llvm_profile_write_file(void);
}

void profile_signal_handler(int sig) {
    __llvm_profile_write_file();
    printf("PGO profile written\n");
    exit(sig);
}

__attribute__((constructor)) void setup_profile_handler(void) {
    signal(SIGTERM, profile_signal_handler);
    signal(SIGINT, profile_signal_handler);
    printf("Profile handler set up\n");
}
#endif

// nothing else to do here, the magic happens inside PhysXJniGlue.h
