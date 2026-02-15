if (shownArtilleryComputer) then {
	if (_isAceLoaded) then {
		switch (true) do {
			case(_ArtyType == 1): {
				if (!RC_allowPortableMortarComputer) then {
					closeDialog 0;
					hintSilent "vanilla artillery computer disabled by mod settings";
					sleep 2;
					hintSilent "";
				};
			};
			case(_ArtyType == 2): {
				if (!RC_allowVehicleMortarComputer) then {
					closeDialog 0;
					hintSilent "vanilla artillery computer disabled by mod settings";
					sleep 2;
					hintSilent "";
				};
			};
			case(_ArtyType == 3): {
				if (!RC_allowHowitzerComputer) then {
					closeDialog 0;
					hintSilent "vanilla artillery computer disabled by mod settings";
					sleep 2;
					hintSilent "";
				};
			};
			case(_ArtyType == 4): {
				if (!RC_allowMLRSComputer) then {
					closeDialog 0;
					hintSilent "vanilla artillery computer disabled by mod settings";
					sleep 2;
					hintSilent "";
				};
			};

			//default {};
		};
	} else {
		switch (true) do {
			//mortars dont work correctly without ace
			/*
			case(_ArtyType == 1): {
				if (RC_allowPortableMortarComputer) then {
					closeDialog 0;
					hintSilent "vanilla artillery computer disabled by mod settings";
					sleep 2;
					hintSilent "";
				};
			};
			case(_ArtyType == 2): {
				if (RC_allowVehicleMortarComputer) then {
					closeDialog 0;
					hintSilent "vanilla artillery computer disabled by mod settings";
					sleep 2;
					hintSilent "";
				};
			};
			*/
			case(_ArtyType == 3): {
				if (!RC_allowHowitzerComputer) then {
					closeDialog 0;
					hintSilent "vanilla artillery computer disabled by mod settings";
					sleep 2;
					hintSilent "";
				};
			};
			case(_ArtyType == 4): {
				if (!RC_allowMLRSComputer) then {
					closeDialog 0;
					hintSilent "vanilla artillery computer disabled by mod settings";
					sleep 2;
					hintSilent "";
				};
			};

			//default {};
		};
	};
};