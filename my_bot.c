//-------------------------------------------------------------------------
//	TheAiGames's Light Riders starting bot by Alcides Schulz (zluchs)
//-------------------------------------------------------------------------

#define NDEBUG
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

#include "variables.h"
#include "settings.h"
#include "game_state.h"
#include "action.h"

char    line[16384];
char    part[3][1024];

int main(void) {
	init_variables();

	while (fgets(line, 16384, stdin) != NULL) {
		if (!strncmp(line, "settings ", 9)) {
			sscanf(&line[9], "%s %s", part[0], part[1]);
			settings(part[0], part[1]);
			continue;
		}
		if (!strncmp(line, "update ", 7)) {
			sscanf(&line[7], "%s %s %s", part[0], part[1], part[2]);
			update(part[0], part[1], part[2]);
			continue;
		}
		if (!strncmp(line, "action ", 7)) {
			sscanf(&line[7], "%s %s", part[0], part[1]);
			action(part[0], part[1]);
			continue;
		}
		if (!strncmp(line, "test", 4)) {
			settings("timebank", "10000");
			settings("time_per_move", "100");
			settings("player_names", "player0,player1");
			settings("your_bot", "player0");
			settings("your_botid", "0");
			settings("field_width", "16");
			settings("field_height", "16");
			update("game", "round", "0");
			update("game", "field", ".,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,0,.,.,.,.,.,.,.,.,1,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.");
			action("move", "10000");
		}
	}

}

// END
