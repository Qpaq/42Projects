#include "FILES/libft.h"

#define WCHAR_MASK_1 "0xxxxxxx"
#define WCHAR_MASK_2 "110xxxxx10xxxxxx"
#define WCHAR_MASK_3 "1110xxxx10xxxxxx10xxxxxx"
#define WCHAR_MASK_4 "11110xxx10xxxxxx10xxxxxx10xxxxxx"

void	apply_mask(char *bin, char *m)
{
	int		length_bin;
	int		length_mask;
	char	*mask;
	int		i;

	mask = ft_strdup(m);
	length_bin = ft_strlen(bin) - 1;
	length_mask = ft_strlen(mask) - 1;
	while (length_mask >= 0 && length_bin >= 0)
	{
		if (mask[length_mask] == 'x')
		{
			mask[length_mask] = bin[length_bin];
			length_bin--;
		}
		length_mask--;
	}
	i = 0;
	while (i < ft_strlen(mask))
	{
		if (mask[i] == 'x')
			mask[i] = '0';
		i++;
	}
	ft_putendl(mask);
}

void	ft_putwchar(wchar_t c)
{
	int		character;
	char	*bin;
	size_t	bin_length;
	int		bits;

	character = (int)c;
	bin = ft_itoa_base(character, 2, 0);
	bin_length = ft_strlen(bin);
	if (bin_length <= 7)
	{
		bits = 1;
		apply_mask(bin, WCHAR_MASK_1);
	}
	else if (bin_length <= 11)
	{
		bits = 2;
		apply_mask(bin, WCHAR_MASK_2);
	}
	else if (bin_length <= 16)
	{
		bits = 3;
		apply_mask(bin, WCHAR_MASK_3);
	}
	else
	{
		bits = 4;
		apply_mask(bin, WCHAR_MASK_4);
	}
}

int main()
{
	ft_putwchar(L'α');
	// א 您 好 α д в у й é
}
