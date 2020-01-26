/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   char_operations.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 11:41:57 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		start_with(char *str, char *starter)
{
	int i;

	i = 0;
	while (starter[i] && starter[i] == str[i])
	{
		i++;
		if (starter[i] == '\0')
			return (1);
	}
	return (0);
}
