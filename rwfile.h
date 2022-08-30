#ifndef RWFILE_H
#define RWFILE_H

/// @file rwfile.h

enum retcodes_get_file_size       /// Enum of return codes of get_file_size()
{                               
ERR_STAT_GET_FILE_SIZE      = -1, ///< get file stat error
ERR_ARGS_NULL_GET_FILE_SIZE = -2  ///< some of pointers args are NULL
};

/// @brief Gets file size in bytes
///
/// @param[in] filename name of file
///
/// @return size of file in bytes on success,
/// -1 on get file stat error
/// -2 if some of pointers args are NULL
int get_file_size(const char *filename);

enum retcodes_read_file       /// Enum of return codes of read_file()
{                             
ERR_FILE_OPEN_READ_FILE = -1, ///< file open error
ERR_ARGS_NULL_READ_FILE = -2  ///< some of pointers args are NULL
};

/// @brief Reads data from file into dynamic memory buffer
///
/// @param[in] filename name of file which read from
/// @param[out] buffer buffer where text store to
/// @param[out] nSymbols number of symbols to read
///
/// @return number of bytes read on success,
/// 0 if nSymbols == 0
/// -1 on file openning error
/// -2 if some of pointers args are NULL
///
/// @note this function does not distinguish empty file and error
int read_file(const char *filename, char *buffer, size_t nSymbols);

/// @brief Count occurences of char in buffer
///
/// @param[in] buffer buffer with text
/// #param[in] ch char to count
///
/// @return number of lines in text,
/// 0 if buffer == NULL
///
/// @note undefined behaviour if buffer is not
/// a pointer to null-terminated byte string
size_t count_char_buffer(const char *buffer, char ch);

/// @brief Read chars in buffer until \n or \0
///
/// @param[in] buffer_ptr pointer to the buffer
///
/// @return length of read string
/// 0 if buffer == NULL
///
/// @note undefined behaviour if buffer is not 
/// a pointer to  null-terminated byte string
size_t read_line_buffer(const char *buffer_ptr);

/// @brief Puts n chars in stdout
///
/// @param[in] start pointer to the start
/// @param[in] length number of chars to read
void putnchar(const char *start, size_t length);

#endif /* RWFILE_H */
