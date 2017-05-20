/*-------------------------------------------------------------------------------
** Game state: field and possible moves
**-----------------------------------------------------------------------------*/

void update_field(char *value) {
	int		i;
	int		j;
	int		fs = field_size();

	if (game_state.field == NULL) {
		game_state.field = (char *)malloc(fs);
		if (game_state.field == NULL) {
			fprintf(stderr, "cannot allocate memory for game field (size=%d).\n", fs);
			return;
		}
	}
	for(i = j = 0; value[j]; j++) {
		if (value[j] == ',') continue;
		if (i < fs)	game_state.field[i] = value[j];
		if (value[j] == '0') game_state.player[0].index = i;
		if (value[j] == '1') game_state.player[1].index = i;
		i++;
	}
}

void update(char *player, char *type, char *value) {
	assert(player != NULL);
	assert(type != NULL);
	assert(value != NULL);

	if (!strcmp(player, "game")) {
		if (!strcmp(type, "round")) {
			game_state.round = atoi(value);
		}
		if (!strcmp(type, "field")) {
			update_field(value);
		}
	}
}

int is_empty(int index) {
	assert(index >= 0 && index < field_size());
	return game_state.field[index] == EMPTY ? TRUE : FALSE;
}

int can_move_up(PLAYER *player) {
	assert(player != NULL);
	assert(player->index >= 0 && player->index < field_size());
	
	if (player->index < game_settings.field_width) return FALSE;
	if (!is_empty(player->index - game_settings.field_width)) return FALSE;

	return TRUE;
}

int can_move_down(PLAYER *player) {
	int		row;

	assert(player != NULL);
	assert(player->index >= 0 && player->index < field_size());

	row = get_row(player->index);
	if (row >= game_settings.field_height - 1) return FALSE;
	if (!is_empty(player->index + game_settings.field_width)) return FALSE;

	return TRUE;
}

int can_move_left(PLAYER *player) {
	int		col;

	assert(player != NULL);
	assert(player->index >= 0 && player->index < field_size());

	col = get_col(player->index);
	if (col < 1) return FALSE;
	if (!is_empty(player->index - 1)) return FALSE;

	return TRUE;
}

int can_move_right(PLAYER *player) {
	int		col;

	assert(player != NULL);
	assert(player->index >= 0 && player->index < field_size());
	
	col = get_col(player->index);
	if (col >= game_settings.field_width - 1) return FALSE;
	if (!is_empty(player->index + 1)) return FALSE;

	return TRUE;
}

void get_moves(PLAYER *player, char *list) {
	int i = 0;
	if (can_move_up(player)) list[i++] = MOVE_UP;
	if (can_move_down(player)) list[i++] = MOVE_DOWN;
	if (can_move_right(player)) list[i++] = MOVE_RIGHT;
	if (can_move_left(player)) list[i++] = MOVE_LEFT;
	list[i] = '\0';
}

//END