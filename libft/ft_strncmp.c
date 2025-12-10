/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:02:07 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/09 17:28:08 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(unsigned char *s1, unsigned char *s2, int n)
{
	int	i;

	i = 0;
	while (n > 0 && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	if (n > 0)
		return (s1[i] - s2[i]);
	return (0);
}
