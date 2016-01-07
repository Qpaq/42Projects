char		*ft_strcat(char *dest, char *src, int size)
{
	char	*temp;
	int		size_dest;
	int		i;

	temp = (char*)malloc((size + 1) * sizeof(char));
	size_dest = 0;
	while (dest != NULL && dest[size_dest])
	{
		temp[size_dest] = dest[size_dest];
		size_dest++;
	}
	i = 0;
	while (i < (size - size_dest))
	{
		temp[size_dest + i] = src[i];
		i++;
	}
	temp[size_dest + i] = '\0';
	free(dest);
	return (temp);
}
