-- Eduardo Espinoza
-- COP 4710
-- AstronautDB Project

-- ******************************************************************************
--INSERT AT LEAST 10 RECORDS IN ALL TABLES
-- ******************************************************************************
INSERT INTO eespinoz_Space_Agency
(name, country, director, leadScientist, dateFounded)
VALUES
('NASA',               'United States',      'Bill Nelson',      'Pam Melroy',         '1958-07-29'),
('CNSA',               'China',              'Zhang Kejian',     'Wu Yanhua',          '1993-04-22'),
('JAXA',               'Japan',              'Yamakawa Hiroshi', 'Suzuki Kazuhiro',    '2003-10-01'),
('ISRO',               'India',              'Shri S. Somanath', 'Dr. P K Mishra',     '1968-08-15'),
('ESA',                'European Union',     'Josef Aschbacher', 'Torben Henriksen',   '1975-05-30'),
('ROSCOSMOS',          'Russia',             'Dmitry Rogozin',    'Vladimir Popovkin', '1992-02-25'),
('SpaceX',             'United States',      'Elon Musk',         'Tom Mueller',       '2002-03-14'),
('Blue Origin',        'United States',      'Jeff Bezos',        'Christopher Jaeger','2000-09-08'),
('Virgin Galactic',    'United States',      'Richard Branson',   'Burt Rutan',        '2004-09-14'),
('ASA',                'Australia',          'Melissa Price',     'Enrico Palermo',    '2018-07-1')
;

INSERT INTO eespinoz_Space_Mission
(description, teamLeader, agencyID)
VALUES
('Fly to the moon', 									   'Kent Shannen',     1),
('Observe sun',                          'Zhen Shu',         2),
('Observe distant planet',							 'Izumi Yuko',       3),
('Collect data on distant stars', 			 'Samir Mohan',      4),
('Test rocket fuel efficency', 					 'Vlado Hans-Peter', 5),
('Successfully land unmaned rocket',     'Elliot Bryon',     6),
('Send first private citizens to space', 'Veronica Aynura',  7),
('Gather data on climate change',        'Shuhrat Candelas', 8),
('Send a rover to Mars',                 'Alessia Tjeerd', 	 9),
('Repair satellite in orbit',            'Ranulph Dimos', 	 10)
;

INSERT INTO eespinoz_Astronaut
(fName, lName, rank, age, dateEnlisted, completedMissions, agencyID)
VALUES
('Alessia',  'Tjeerd',  	   'Command Pilot',        30, '2018-05-25',  21,    9),
('Ranulph',  'Dimos', 		   'Commander',            45, '2019-10-12',  10,    10),
('Zhen',     'Shu',          'Misson Specialist',    34, '2017-11-11',  13,    2),
('Kent',     'Shannen',      'Spacecraft Commander', 29, '2021-02-29',  5,     1),
('Elliot',   'Bryon',        'Pilot',                53, '2010-04-30',  102,   5),
('Samir',    'Mohan',        'Commander',            44, '2020-12-23',  15,    4),
('Shuhrat',  'Candelas',     'Spacecraft Commander', 34, '2021-07-03',  8,     8),
('Veronica', 'Aynura',       'Spacecraft Pilot',     30, '2021-11-23',  10,    7),
('Vlado',    'Hans-Peter',   'Pilot Cosmonaut',      55, '2002-09-26',  325,   6),
('Izumi',    'Yuko',         'Commander',            32, '2022-06-10',  0,     3)
;

INSERT INTO eespinoz_Rocket_Ship
(rocketClass, payload_kg, height_m, astroID)
VALUES
('Flyby',       24060, 120.52,   1),
('Orbiter',     20532, 73.28,    2),
('Orbiter',     21221, 101.45,   3),
('Atmospheric', 21330, 110.47,   4),
('Lander',      23002, 115.34,   5),
('Rover',       22300, 67.12,    6),
('Observatory', 26700, 70.31,    7),
('Orbiter',     21332, 87.87,    8),
('Lander',      22100, 100.79,   9),
('Orbiter',     27911, 90.44,   10)
;

INSERT INTO eespinoz_Mission_Objectives
(missionID, astroID, tasks)
VALUES
(1,  4,   'Gather lunar rocks'),
(2,  3,   'Observe sun for unusual solar activity'),
(3,  10,  'Search for more Earth-like planets'),
(4,  6,   'Observe star orbits'),
(5,  9,   'Test minimum fuel needed'),
(6,  5,   'Test landing sensors'),
(7,  9,   'Prepare citizens for flight'),
(8,  7,   'Gather satellte data on glaciers'),
(9,  1,   'Train astronauts for harsh conditons'),
(10, 2,   'Prepare for spacewalk to do repairs')
;

-- ********************************************************************************************************************************************************
-- BASIC SQL OPERATIONS 
-- ********************************************************************************************************************************************************

-- ********************************************************************************
--VALIDATE INSERTION OF AT LEAST 10 RECORDS IN ALL TABLES
-- ********************************************************************************
SELECT * FROM eespinoz_Space_Agency;
SELECT * FROM eespinoz_Space_Mission;
SELECT * FROM eespinoz_Astronaut;
SELECT * FROM eespinoz_Rocket_Ship;
SELECT * FROM eespinoz_Mission_Objectives;

-- ******************************************************************************
--DELETE AT LEAST 1 RECORD FROM ALL TABLES
-- ******************************************************************************
DELETE FROM eespinoz_Space_Agency
WHERE country = 'Australia';

DELETE FROM eespinoz_Space_Mission
WHERE description = 'Observe sun';

DELETE FROM eespinoz_Astronaut
WHERE rank = 'Pilot';

DELETE FROM eespinoz_Rocket_Ship
WHERE payload_kg = 22100;

DELETE FROM eespinoz_Mission_Objectives
WHERE tasks = 'Test landing sensors';


-- ********************************************************************************
--VALIDATE  DELETE
-- ********************************************************************************
SELECT * FROM eespinoz_Space_Agency;
SELECT * FROM eespinoz_Space_Mission;
SELECT * FROM eespinoz_Astronaut;
SELECT * FROM eespinoz_Rocket_Ship;
SELECT * FROM eespinoz_Mission_Objectives;

-- ******************************************************************************
--UPDATE AT LEAST 1 RECORD FROM ALL TABLES
-- ******************************************************************************
UPDATE eespinoz_Space_Agency
SET director = 'Bill Smith'
WHERE agencyID = 1;

UPDATE eespinoz_Space_Mission
SET description = 'Test max fuel capacity'
WHERE description = 'Test rocket fuel efficency';

UPDATE eespinoz_Astronaut
SET completedMissionS = 2
WHERE astroID = 10;

UPDATE eespinoz_Rocket_Ship
SET height_m = 113.43
WHERE rocketID = 4;

UPDATE eespinoz_Mission_Objectives
SET tasks = 'Search for alien life'
WHERE missionID = 3 AND astroID = 10;

-- ********************************************************************************
--VALIDATE  INSERTION
-- ********************************************************************************
SELECT * FROM eespinoz_Space_Agency;
SELECT * FROM eespinoz_Space_Mission;
SELECT * FROM eespinoz_Astronaut;
SELECT * FROM eespinoz_Rocket_Ship;
SELECT * FROM eespinoz_Mission_Objectives;
