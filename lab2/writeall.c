/*[writeall]*/
ssize_t writeall(int fd, const void *buf, ssize_t nbyte)
{
	ssize_t nwritten = 0, n;

	do {
		if ((n = write(fd, &((const char *)buf)[nwritten], nbyte - nwritten)) == -1) {
			if (errno == EINTR) // Eintr dotyczy sytuacji gdy coś sie przerwało np coś nie styka, nalezy kontynyuowac
				continue;
			else
				return -1;
		}
		nwritten += n;
	} while (nwritten < nbyte);
	return nwritten;
}