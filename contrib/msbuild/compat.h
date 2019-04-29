#ifdef __cplusplus
extern "C" {
#endif
__declspec( dllimport ) extern char strbuf_slopbuf[];
__declspec( dllimport ) extern const char *empty_argv[];
#define strbuf_slopbuf __strbuf_slopbuf
#define empty_argv __empty_argv
#define extern __declspec( dllimport ) extern
#include <msvc.h>
#include "git-compat-util.h"
#undef extern
#include "strbuf.h"
#include "argv-array.h"
#define extern __declspec( dllimport ) extern
#include "version.h"
#define git_version_string GIT_VERSION
#define git_built_from_commit_string GIT_BUILT_FROM_COMMIT
#ifdef __cplusplus
}
#endif