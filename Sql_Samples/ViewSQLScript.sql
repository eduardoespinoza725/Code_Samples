-- COP4710
-- ViewSQLScript

-- Three statements that drop the three views
DROP VIEW IF EXISTS ViewRocketCaptain;
DROP VIEW IF EXISTS ViewMissionOverview;
DROP VIEW IF EXISTS ViewTotalCompletedMissions;

-- A statement that creates a view that combines at least 2 tables
CREATE VIEW ViewRocketCaptain AS
SELECT fName, LName, rank, rocketClass
FROM eespinoz_Astronaut
INNER JOIN
eespinoz_Rocket_Ship
ON eespinoz_Astronaut.astroID = eespinoz_Rocket_Ship.astroID
WHERE
eespinoz_Astronaut.completedMissions > 5;

-- A statement that creates a view that combines at least 3 tables
CREATE VIEW ViewMissionOverview AS
SELECT name, country, teamLeader, description, tasks
FROM eespinoz_Space_Agency
INNER JOIN
eespinoz_Space_Mission
ON eespinoz_Space_Agency.agencyID = eespinoz_Space_Mission.agencyID
INNER JOIN
eespinoz_Mission_Objectives
ON eespinoz_Space_Mission.missionID = eespinoz_Mission_Objectives.missionID
WHERE country = 'United States';

-- A statement that creates a view that uses an aggregate function
CREATE VIEW ViewTotalCompletedMissions AS
SELECT country, SUM(completedMissions)
FROM eespinoz_Space_Agency
INNER JOIN
eespinoz_Astronaut
ON eespinoz_Space_Agency.agencyID = eespinoz_Astronaut.agencyID
WHERE country = 'United States';


-- A select that utilizes View 1
SELECT * FROM ViewRocketCaptain;

-- A select that utilizes View 2
SELECT * FROM ViewMissionOverview;

-- A select that utilizes View 3
SELECT * FROM ViewTotalCompletedMissions;