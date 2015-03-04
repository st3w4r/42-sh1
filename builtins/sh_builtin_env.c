/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 11:13:35 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/02 11:13:39 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_sh1.h"

static void sh_print_env(char **env)
{
    while (env && *env)
    {
        ft_putendl(*env);
        ++env;
    }
}

t_uint	sh_args_len(char **argv)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (argv[i])
    {
        if (ft_strchr(argv[i], '='))
            count++;
        ++i;
    }
    return (count);
}

void	sh_builtin_env(char **argv, char **env)
{
    int i;
    t_uint count;
    t_uint arg_len;
    char **new_env;
    char **array_path;


    i = 0;
    new_env = NULL;

    if (!argv || !(*argv))
        return ;

    if (ft_strcmp(argv[1], "-i") == 0)
    {
        i = 2;
        arg_len = sh_args_len(argv);
        if (!(new_env = (char**)malloc(sizeof(char *) * arg_len + 1)))
            ft_malloc_error();
        arg_len = 0;
    }
    else
    {
        i = 1;
        arg_len = sh_tablen(env) + sh_args_len(argv);
        if (!(new_env = (char**)malloc(sizeof(char *) * arg_len + 1)))
            ft_malloc_error();
        count = 0;
        while (env && env[count])
            new_env[count] = env[count], count++;
        arg_len -= sh_args_len(argv);
    }

    while (argv[i] && ft_strchr(argv[i], '='))
        new_env[arg_len++] = ft_strdup(argv[i]), ++i;

///Execution command
    if (argv[i])
    {
        array_path = sh_parse_path(sh_get_env("PATH", new_env));
        
        sh_search_exec(array_path, &(argv[i]), new_env);
    }
    else
        sh_print_env(new_env);


}
