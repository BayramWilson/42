/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:58:17 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/08 14:24:33 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(char x)
{
	if (x >= '0' && x <= '9')
		return (1);
	else
		return (0);
}

int	ft_isspace(char x)
{
	if ((x >= '\t' && x <= '\r') || x == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	symbol;

	i = 0;
	result = 0;
	symbol = 1;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				symbol = -symbol;
			i++;
		}
		while (ft_isdigit(str[i]))
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		return (result * symbol);
	}
	return (0);
}
