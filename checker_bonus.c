


int apply_operation(t_array *stack_a, t_array *stack_b, char *operation) 
{
    if (!ft_strcmp(operation, "sa")) 
        return s(stack_a, 'a');
    else if (!ft_strcmp(operation, "sb")) 
        return s(stack_b, 'b');
    else if (!ft_strcmp(operation, "ra")) 
        return r(stack_a, 'a');
    else if (!ft_strcmp(operation, "rb")) 
        return r(stack_b, 'b');
    else if (!ft_strcmp(operation, "rra")) 
        return rr(stack_a, 'a');
    else if (!ft_strcmp(operation, "rrb")) 
        return rr(stack_b, 'b');
    // Add other operations as needed...

    return 0; // Invalid operation
}

int execute_operations(t_array *stack_a, t_array *stack_b) 
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) 
    {
        line[strcspn(line, "\n")] = 0; // remove newline
        if (!apply_operation(stack_a, stack_b, line)) 
        {
            free(line);
            return 0; // Invalid operation
        }
    }
    free(line);
    return 1; 
}

void check_stacks(t_array *stack_a, t_array *stack_b) 
{
    if (ft_arrissorted(stack_a) && stack_b->l == 0) 
    {
        printf("OK\n");
    } 
    else 
    {
        printf("KO\n");
    }
}

static int	read_fd(int fd, t_file_info *buffer)
{
	int		n_bytes;
	char	tmp[BUFFER_SIZE + 1];
	char	*tmp2;

	while (!ft_strchr(buffer->content, '\n') && !buffer->eof)
	{
		n_bytes = read(fd, tmp, BUFFER_SIZE);
		if (n_bytes == -1)
			return (0);
		buffer->eof = n_bytes != BUFFER_SIZE;
		tmp[n_bytes] = '\0';
		tmp2 = ft_strjoin(buffer->content, tmp);
		if (tmp2 == NULL)
			return (0);
		if (buffer->content != NULL)
			free(buffer->content);
		buffer->content = tmp2;
	}
	return (1);
}


int	main(int size, char *argv[])
{
	int			*input;
	int			tm;
	t_array		*map;
	t_stacks	*stks;
	t_n_base	*n_base;

	tm = 0;
	input = parse_input(&size, argv);
	if (!input)
		return (0);
	reverse_array(input, size);
	map = normalize_input(input, size);
	stks = init_stacks(map, size);



	/** DEBUG */

	// printf("\ntotal moves: %d\n", tm);
	// printArray("\nmap\n", map->a, size);
	// printArray("\nnorm\n", stks->a->a, size);
	// printArray("result", dnrmlize(input, map->a, stks->a->a, size), size);

	
	/** DEBUG */

		
	free_stacks(stks);
	free(n_base);
	ft_arrfree(map);
	free(input);
	return (0);
	//What about trying in base 5 by simply using the % operator?!!
}