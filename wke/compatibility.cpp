
#if _MSC_VER>=1900

#include <stdio.h>

_ACRTIMP_ALT FILE* __cdecl __acrt_iob_func(unsigned);

#if defined(__cplusplus)
extern "C"
{
#endif

FILE* __cdecl __iob_func(unsigned i)
{
    return __acrt_iob_func(i);
}

int __cdecl _sopen_dispatch(
	_In_z_ char const* _FileName,
	_In_   int         _OFlag,
	_In_   int         _ShFlag,
	_In_   int         _PMode,
	_Out_  int*        _PFileHandle,
	_In_   int         _BSecure
);

#ifdef __cplusplus
}
#endif
 
// In VS2015, the type of its first param is 'char const * cosnt', not 'char const *'.
// So far, we cannot overload _open! VS2017 will fix it?
 int __cdecl _open(char const *_FileName, int _OFlag, int _PMode)
 {
 	int _FileHandle;
 	#define _DENYNO      0x40    // deny none mode
 	// Last parameter passed as 0 because we don't want to validate pmode from _open
 	int const _Result = _sopen_dispatch(_FileName, _OFlag, _DENYNO, _PMode, &_FileHandle, 0);
 	return _Result ? -1 : _FileHandle;
 }

#endif // _MSC_VER>=1900