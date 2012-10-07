SET(Subversion_FOUND FALSE)
SET(Subversion_SVN_FOUND FALSE)

FIND_PROGRAM(Subversion_SVN_EXECUTABLE svn
	DOC "subversion command line client")
MARK_AS_ADVANCED(Subversion_SVN_EXECUTABLE)

IF(Subversion_SVN_EXECUTABLE)
	SET(Subversion_SVN_FOUND TRUE)
	SET(Subversion_FOUND TRUE)

	MACRO(Subversion_WC_INFO dir prefix)
		# the subversion commands should be executed with the C locale, otherwise
		# the message (which are parsed) may be translated, Alex
		SET(_Subversion_SAVED_LC_ALL "$ENV{LC_ALL}")
		SET(ENV{LC_ALL} C)

		EXECUTE_PROCESS(COMMAND ${Subversion_SVN_EXECUTABLE} --version
			WORKING_DIRECTORY ${dir}
			OUTPUT_VARIABLE Subversion_VERSION_SVN
			OUTPUT_STRIP_TRAILING_WHITESPACE)

		EXECUTE_PROCESS(COMMAND ${Subversion_SVN_EXECUTABLE} info ${dir}
			OUTPUT_VARIABLE ${prefix}_WC_INFO
			ERROR_VARIABLE Subversion_svn_info_error
			RESULT_VARIABLE Subversion_svn_info_result
			OUTPUT_STRIP_TRAILING_WHITESPACE)

		IF(NOT ${Subversion_svn_info_result} EQUAL 0)
			set(Subversion_SVN_FOUND FALSE)
			set(Subversion_FOUND FALSE)

			warn("Command \"${Subversion_SVN_EXECUTABLE} info ${dir}\" failed with output:\n${Subversion_svn_info_error}")
		ELSE(NOT ${Subversion_svn_info_result} EQUAL 0)

			STRING(REGEX REPLACE "^(.*\n)?svn, version ([.0-9]+).*"
				"\\2" Subversion_VERSION_SVN "${Subversion_VERSION_SVN}")
			STRING(REGEX REPLACE "^(.*\n)?URL: ([^\n]+).*"
				"\\2" ${prefix}_WC_URL "${${prefix}_WC_INFO}")
			STRING(REGEX REPLACE "^(.*\n)?Revision: ([^\n]+).*"
				"\\2" ${prefix}_WC_REVISION "${${prefix}_WC_INFO}")
			STRING(REGEX REPLACE "^(.*\n)?Last Changed Author: ([^\n]+).*"
				"\\2" ${prefix}_WC_LAST_CHANGED_AUTHOR "${${prefix}_WC_INFO}")
			STRING(REGEX REPLACE "^(.*\n)?Last Changed Rev: ([^\n]+).*"
				"\\2" ${prefix}_WC_LAST_CHANGED_REV "${${prefix}_WC_INFO}")
			STRING(REGEX REPLACE "^(.*\n)?Last Changed Date: ([^\n]+).*"
				"\\2" ${prefix}_WC_LAST_CHANGED_DATE "${${prefix}_WC_INFO}")

		ENDIF(NOT ${Subversion_svn_info_result} EQUAL 0)

		# restore the previous LC_ALL
		SET(ENV{LC_ALL} ${_Subversion_SAVED_LC_ALL})

	ENDMACRO(Subversion_WC_INFO)
ENDIF(Subversion_SVN_EXECUTABLE)

