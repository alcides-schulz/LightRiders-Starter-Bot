/*-------------------------------------------------------------------------------
** Definitions & variables
**-----------------------------------------------------------------------------*/

#define TRUE	1
#define FALSE	0

#define MOVE_NONE	'-'
#define MOVE_UP		'u'
#define MOVE_DOWN	'd'
#define MOVE_RIGHT	'r'
#define MOVE_LEFT	'l'

#define MOVE_LIST	"udrl"

#define EMPTY	'.'
#define WALL	'x'

typedef struct s_game_settings {
	int     timebank;
	int     time_per_move;
	char    player_names[512];
	char    my_bot_name[512];
	int		my_bot_id;
	int     field_height;
	int     field_width;
}   GAME_SETTINGS;

typedef struct s_player {
	char	id;
	int		index;
	int		count;
}   PLAYER;

typedef struct s_game_state {
	int     round;
	char	*field;
	PLAYER	player[2];
}   GAME_STATE;

GAME_SETTINGS	game_settings;
GAME_STATE      game_state;

void init_variables(void) {
	memset(&game_state, 0, sizeof(GAME_STATE));
	memset(&game_settings, 0, sizeof(GAME_SETTINGS));
	game_state.player[0].id = '0';
	game_state.player[1].id = '1';
}

//END
