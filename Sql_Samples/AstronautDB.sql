DROP TABLE IF EXISTS eespinoz_Mission_Objectives;
DROP TABLE IF EXISTS eespinoz_Rocket_Ship;
DROP TABLE IF EXISTS eespinoz_Astronaut;
DROP TABLE IF EXISTS eespinoz_Space_Mission;
DROP TABLE IF EXISTS eespinoz_Space_Agency;

CREATE TABLE eespinoz_Space_Agency (
	agencyID	        	INT AUTO_INCREMENT,
	name			    	VARCHAR(20),
	country				CHAR(20),
	director    			VARCHAR(20),
	leadScientist  			VARCHAR(20),
	dateFounded  			DATE,
	PRIMARY KEY (agencyID)
);

CREATE TABLE eespinoz_Space_Mission (
	missionID		INT AUTO_INCREMENT,
	description		VARCHAR(50),
	teamLeader		VARCHAR(20),
	agencyID		INT,
	PRIMARY KEY (missionID),
	FOREIGN KEY (agencyID) REFERENCES eespinoz_Space_Agency (agencyID) ON DELETE CASCADE
);

CREATE TABLE eespinoz_Astronaut(
	astroID			INT AUTO_INCREMENT,
	fName 			VARCHAR(20),
	lName			VARCHAR(20),
	rank			VARCHAR(20),
	age			INT,
	dateEnlisted 		DATE,
	completedMissions	INT,
	agencyID   		INT,
	PRIMARY KEY (astroID),
	FOREIGN KEY (agencyID) REFERENCES eespinoz_Space_Agency (agencyID) ON DELETE CASCADE
);

CREATE TABLE eespinoz_Rocket_Ship (
	rocketID		INT AUTO_INCREMENT,
	rocketClass  		VARCHAR(20),
	payload_kg   		FLOAT,
	height_m      		DOUBLE(7,2),
	astroID		     	INT,
	PRIMARY KEY (rocketID),
	FOREIGN KEY (astroID) REFERENCES eespinoz_Astronaut (astroID) ON DELETE CASCADE
);

CREATE TABLE eespinoz_Mission_Objectives (
	missionID 	INT,
	astroID		INT,
	tasks		VARCHAR(50),
	PRIMARY KEY (missionID, astroID),
	FOREIGN KEY (missionID) REFERENCES eespinoz_Space_Mission (missionID) ON DELETE CASCADE,
	FOREIGN KEY (astroID) REFERENCES eespinoz_Astronaut (astroID) ON DELETE CASCADE
);
