/*-------------------------------------------------------------------------------
** Action: execute moves
**-----------------------------------------------------------------------------*/

char get_random_move(int turn) {
	char	list[5];

	get_moves(&game_state.player[turn], list);

	if (strlen(list) == 0) return MOVE_NONE;

	return list[rand() % strlen(list)];
}

void do_moves(int time) {
	char	move;
	
	move = get_random_move(game_settings.my_bot_id);

	// NOTE: fprintf to stdout, 'printf' alone won't do it.
	if (move == MOVE_UP) fprintf(stdout, "up");
	if (move == MOVE_DOWN) fprintf(stdout, "down");
	if (move == MOVE_LEFT) fprintf(stdout, "left");
	if (move == MOVE_RIGHT) fprintf(stdout, "right");

	fprintf(stdout, "\n");
	fflush(stdout);
}

void action(char *type, char *time) {
	assert(type != NULL);
	assert(time != NULL);

    if (!strcmp(type, "move"))
		do_moves(atoi(time));
	else
		fprintf(stderr, "action: unknown type: [%s]\n", type);
}


//END
