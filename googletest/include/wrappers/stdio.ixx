module;
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#define LEGACY_S_ISDIR(mode) S_ISDIR(mode)
#undef S_ISDIR

#define LEGACY_errno (*__errno_location ())
#undef errno

export module wrapper.stdio;

export {
  using ::fileno;
  using ::isatty;
  using ::rmdir;
  using ::stat;

  auto S_ISDIR(auto mode) -> bool { return LEGACY_S_ISDIR(mode); }
  const auto errno = LEGACY_errno;
}
