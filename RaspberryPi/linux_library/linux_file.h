#ifndef _LINUX_FILE_H_
#define _LINUX_FILE_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

class LinuxFile
{
private:
	int m_Handle;

public:
	LinuxFile(const char *pFile, int flags = O_RDWR)
	{
		m_Handle = open(pFile, flags);
	}

	~LinuxFile()
	{
		if (m_Handle != -1)
			close(m_Handle);
	}

	size_t Write(const void *pBuffer, size_t size)
	{
		return write(m_Handle, pBuffer, size);
	}

	size_t Read(void *pBuffer, size_t size)
	{
		return read(m_Handle, pBuffer, size);
	}

	size_t Write(const char *pText)
	{
		return Write(pText, strlen(pText));
	}

	size_t Write(int number)
	{
		char szNum[32];
		snprintf(szNum, sizeof(szNum), "%d", number);
		return Write(szNum);
	}
};

#endif