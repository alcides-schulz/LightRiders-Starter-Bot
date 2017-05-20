/*-------------------------------------------------------------------------------
** Game settings
**-----------------------------------------------------------------------------*/

void settings(char *type, char *value) {

    assert(type != NULL);
    assert(value != NULL);

	if (!strcmp(type, "timebank"))
		game_settings.timebank = atoi(value);
	else
	if (!strcmp(type, "time_per_move"))
		game_settings.time_per_move = atoi(value);
	else
	if (!strcmp(type, "player_names"))
		strcpy(game_settings.player_names, value);
	else
	if (!strcmp(type, "your_bot"))
		strcpy(game_settings.my_bot_name, value);
	else
	if (!strcmp(type, "your_botid"))
		game_settings.my_bot_id = atoi(value);
	else
    if (!strcmp(type, "field_height"))
        game_settings.field_height = atoi(value);
    else
    if (!strcmp(type, "field_width"))
        game_settings.field_width = atoi(value);
    else
        fprintf(stderr, "settings: unknown type: [%s]\n", type);
}

int field_size(void) {
	return game_settings.field_height * game_settings.field_width;
}

int get_row(int index) {
	assert(index >= 0 && index < field_size());
	return index / game_settings.field_height;
}

int get_col(int index) {
	assert(index >= 0 && index < field_size());
	return index % game_settings.field_width;
}

//END
