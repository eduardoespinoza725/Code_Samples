-- Stored Procedure Script


DROP PROCEDURE IF EXISTS show_AllAgenciesCompletedMissions;
DROP PROCEDURE IF EXISTS show_TotalCompletedMissionsbyAgency;
DROP PROCEDURE IF EXISTS get_TotalCompletedMissions;

DELIMITER //

CREATE PROCEDURE show_AllAgenciesCompletedMissions()
BEGIN
    SELECT name, SUM(completedMissions)
    FROM eespinoz_Space_Agency
    INNER JOIN
    eespinoz_Astronaut
    ON eespinoz_Space_Agency.agencyID = eespinoz_Astronaut.agencyID
    GROUP BY (eespinoz_Astronaut.agencyID);    
    
END // 

CREATE PROCEDURE show_TotalCompletedMissionsbyAgency
(IN AGENCY_ID INT)
BEGIN
    SELECT country, SUM(completedMissions)
    FROM eespinoz_Space_Agency
    INNER JOIN
    eespinoz_Astronaut
    ON eespinoz_Space_Agency.agencyID = eespinoz_Astronaut.agencyID
    WHERE eespinoz_Space_Agency.agencyID = AGENCY_ID;
    
END // 

CREATE PROCEDURE get_TotalCompletedMissions
(IN agency_ID INT, OUT TotalCompleted NUMERIC)
BEGIN
    SELECT SUM(completedMissions) INTO TotalCompleted
    FROM eespinoz_Space_Agency
    INNER JOIN
    eespinoz_Astronaut
    ON eespinoz_Space_Agency.agencyID = eespinoz_Astronaut.agencyID
    WHERE eespinoz_Space_Agency.agencyID = agency_ID;
    
END //

DELIMITER ;

CALL show_AllAgenciesCompletedMissions();
CALL show_TotalCompletedMissionsByAgency(6);
CALL get_TotalCompletedMissions(6, @TotalCompletedMissions);
SELECT @TotalCompletedMissions;