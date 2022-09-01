-- COP4710
-- TransactionSQLScript.sql


-- Two statements that drop the two stored procedures.
DROP PROCEDURE IF EXISTS NewAstronaut;
DROP PROCEDURE IF EXISTS NewMission;

DELIMITER //

-- A statement to create a stored procedure with handlers for sqlexception and sqlwarning that will trigger an exception when called 
CREATE PROCEDURE NewAstronaut()
BEGIN
    DECLARE exit handler for sqlexception
    BEGIN
        ROLLBACK;
        SELECT 'sql exception';
    END;
    
    DECLARE exit handler for sqlwarning 
    BEGIN
        ROLLBACK;
        SELECT 'sql warning';
    END;
    
    START TRANSACTION;
    
    -- Remove astronaut from Astronaut table
    DELETE FROM eespinoz_Astronaut
    WHERE fName = 'Vlado';
    
    -- Insert new astronaut into Astronaut table
    INSERT INTO eespinoz_Astronaut
    (fName, lName, rank, age, dateEnlisted, completedMissions, agencyID)
    VALUES
    ('Ekatarina', 'Nikolayev', 'Pilot Cosmonaut', 26, '2022-07-03', 0, 6);
    
    COMMIT;
    
END //

-- Create procedure that will trigger an exception when called
CREATE PROCEDURE NewMission()
BEGIN
    DECLARE exit handler for sqlexception
    BEGIN
        ROLLBACK;
        SELECT 'sql exception';
    END;
    
    DECLARE exit handler for sqlwarning
    BEGIN
        ROLLBACK;
        SELECT 'sql warning';
    END;
    
    START TRANSACTION;
    
    INSERT INTO eespinoz_Space_Mission
    VALUES
    ('Moon Walk', 'Ekatarina Nikolayev', 5);
    
    COMMIT;
    
END //

DELIMITER ;

-- Call the stored procedure NewAstronaut
CALL NewAstronaut();
CALL NewMission();