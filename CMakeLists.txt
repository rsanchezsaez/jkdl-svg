cmake_minimum_required (VERSION 2.6)
project (jkdl-svg)

# This part is based on FindFreeImage.cmake in the nvidia-texture-tools project.
# http://code.google.com/p/nvidia-texture-tools/
# This file has been released under the MIT license.

#
# Try to find the FreeImagePlus library and include path.
# Once done this will define :
#
# FREEIMAGE_FOUND
# FREEIMAGE_INCLUDE_PATH
# FREEIMAGE_LIBRARY
# FIP_FOUND
# FIP_INCLUDE_PATH
# FIP_LIBRARY
 

IF (WIN32)
  FIND_PATH( FREEIMAGE_INCLUDE_PATH FreeImage.h
		${FREEIMAGE_ROOT_DIR}/include
		${FREEIMAGE_ROOT_DIR}
		DOC "The directory where FreeImage.h resides")
	FIND_PATH( FIP_INCLUDE_PATH FreeImagePlus.h
		${FIP_ROOT_DIR}/include
		${FIP_ROOT_DIR}
		DOC "The directory where FreeImagePlus.h resides")
	FIND_LIBRARY( FREEIMAGE_LIBRARY
		NAMES FreeImage freeimage
		PATHS
		${FREEIMAGE_ROOT_DIR}/lib
		${FREEIMAGE_ROOT_DIR}
		DOC "The FreeImage library")
	FIND_LIBRARY( FIP_LIBRARY
		NAMES FreeImagePlus freeimageplus
		PATHS
		${FIP_ROOT_DIR}/lib
		${FIP_ROOT_DIR}
		DOC "The FreeImagePlus library")
ELSE (WIN32)
	FIND_PATH( FIP_INCLUDE_PATH FreeImagePlus.h
		/usr/include
		/usr/local/include
		/sw/include
		/opt/local/include
		DOC "The directory where FreeImagePlus.h resides")
        FIND_PATH( FREEIMAGE_INCLUDE_PATH FreeImage.h
                /usr/include
                /usr/local/include
                /sw/include
                /opt/local/include
                DOC "The directory where FreeImage.h resides")
	FIND_LIBRARY( FIP_LIBRARY
		NAMES FreeImagePlus freeimageplus
		PATHS
		/usr/lib64
		/usr/lib
		/usr/local/lib64
		/usr/local/lib
		/sw/lib
		/opt/local/lib
		DOC "The FreeImagePlus library")
        FIND_LIBRARY( FREEIMAGE_LIBRARY
                NAMES FreeImage freeimage
                PATHS
                /usr/lib64
                /usr/lib
                /usr/local/lib64
                /usr/local/lib
                /sw/lib
                /opt/local/lib
                DOC "The FreeImage library")

ENDIF (WIN32)

SET(FREEIMAGE_LIBRARIES ${FREEIMAGE_LIBRARY})
SET(FIP_LIBRARIES ${FIP_LIBRARY})

IF (FREEIMAGE_INCLUDE_PATH AND FREEIMAGE_LIBRARY)
  SET( FREEIMAGE_FOUND TRUE CACHE BOOL "Set to TRUE if FreeImage is found, FALSE otherwise" FORCE)
ELSE (FREEIMAGE_INCLUDE_PATH AND FREEIMAGE_LIBRARY)
	SET( FREEIMAGE_FOUND FALSE CACHE BOOL "Set to TRUE if FreeImage is found, FALSE otherwise" FORCE)
ENDIF (FREEIMAGE_INCLUDE_PATH AND FREEIMAGE_LIBRARY)

IF (FIP_INCLUDE_PATH AND FIP_LIBRARY)
  SET( FIP_FOUND TRUE CACHE BOOL "Set to TRUE if FreeImagePlus is found, FALSE otherwise" FORCE)
ELSE (FIP_INCLUDE_PATH AND FIP_LIBRARY)
	SET( FIP_FOUND FALSE CACHE BOOL "Set to TRUE if FreeImagePlus is found, FALSE otherwise" FORCE)
ENDIF (FIP_INCLUDE_PATH AND FIP_LIBRARY)

MARK_AS_ADVANCED(
	FIP_FOUND 
	FIP_LIBRARY
	FIP_LIBRARIES
	FIP_INCLUDE_PATH
  FREEIMAGE_FOUND 
	FREEIMAGE_LIBRARY
	FREEIMAGE_LIBRARIES
	FREEIMAGE_INCLUDE_PATH)

# End looking for FreeImage and FIP

if (NOT FREEIMAGE_FOUND)
  message (FATAL_ERROR "Unable to find FreeImage.")
endif (NOT FREEIMAGE_FOUND)
if (NOT FIP_FOUND)
  message (FATAL_ERROR "Unable to find FreeImagePlus.")
endif (NOT FIP_FOUND)

add_subdirectory (src)
add_subdirectory (tests)

