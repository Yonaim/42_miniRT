
int	fmt_atoi(const char **str)
{
	int	n;

	n = 0;
	while ('0' <= **str && **str <= '9')
	{
		n *= 10;
		n += **str - '0';
		(*str)++;
	}
	return (n);
}
