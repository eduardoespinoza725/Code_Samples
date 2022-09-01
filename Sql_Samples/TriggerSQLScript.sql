-- cop4710

-- Drop Log table statement
DROP TABLE IF EXISTS DataLog;

-- Create Log table statement
CREATE TABLE DataLog (
    ActionID                INT AUTO_INCREMENT PRIMARY KEY,
    USER                    VARCHAR(50)  NOT NULL,
    Action_Taken            VARCHAR(200) NOT NULL,
    TableName               VARCHAR(50)  NOT NULL,
    TimeStamp               TIMESTAMP
); 

-- Drop tringgers 
DROP TRIGGER IF EXISTS TriggerBeforeInsertRocket;
DROP TRIGGER IF EXISTS InsertRocket;
DROP TRIGGER IF EXISTS UpdateRocket;
DROP TRIGGER IF EXISTS DeleteRocket;

DELIMITER // 

-- INSERT BEFORE TRIGGER
CREATE TRIGGER TriggerBeforeInsertRocket
BEFORE INSERT
ON eespinoz_Rocket_Ship
FOR EACH ROW
BEGIN

if(New.astroID <= 0) THEN
    SIGNAL SQLSTATE '45000'
    SET MESSAGE_TEXT = '** Invalid astroID - Record not added **';

elseif((new.height_m < 60) or (new.height_m > 200)) THEN
    SIGNAL SQLSTATE '45000'
    SET MESSAGE_TEXT = '** Invalid hieght entered - Record not added **';

else 
    SELECT CHARACTER_LENGTH(New.rocketClass) INTO @Rclass;
    if((@Rclass < 2) or (@Rclass is NULL)) THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = '** Rocket class is to short or emtpy - Record not added **';
   
    END If;
   
END If;
    
END //

DELIMITER ;
       
       
       
-- INSERT AFTER TRIGGER
DELIMITER //

CREATE TRIGGER InsertRocket
AFTER INSERT
ON eespinoz_Rocket_Ship 
FOR EACH ROW
BEGIN

       
INSERT INTO DataLog
(USER, Action_Taken, TableName, TimeStamp)
VALUES
(CURRENT_USER(), "Insert", "rocketClass", now());

END //
       
DELIMITER ;
       

-- UPDATE AFTER TRIGGER
DELIMITER //

CREATE TRIGGER UpdateRocket
AFTER UPDATE
ON eespinoz_Rocket_Ship 
FOR EACH ROW
BEGIN

INSERT INTO DataLog
(USER, Action_Taken, TableName, TimeStamp)
VALUES
(CURRENT_USER(), "Update", "rocketClass", now());

END //
       
DELIMITER ;
       
       
-- DELETE AFTER TRIGGER
DELIMITER //

CREATE TRIGGER DeleteRocket
AFTER DELETE
ON eespinoz_Rocket_Ship 
FOR EACH ROW
BEGIN
       
INSERT INTO DataLog
(USER, Action_Taken, TableName, TimeStamp)
VALUES
(CURRENT_USER(), "Delete", "rocketClass", now());

END //
       
DELIMITER ;

-- **************************************************************************************************
-- **************************************************************************************************

-- Invalid Data to fire Trigger 1
INSERT INTO eespinoz_Rocket_Ship 
(rocketClass, payload_kg, height_m, astroID)
VALUES
('Heavy', 24000, 100.52, 0);

INSERT INTO eespinoz_Rocket_Ship 
(rocketClass, payload_kg, height_m, astroID)
VALUES
('Heavy', 2000, 1000.52, 11);

INSERT INTO eespinoz_Rocket_Ship 
(rocketClass, payload_kg, height_m, astroID)
VALUES
('H', 2000, 100.52, 11);

SELECT * FROM DataLog;


-- Valid Data for Trigger 1
INSERT INTO eespinoz_Rocket_Ship 
(rocketClass, payload_kg, height_m)
VALUES
('Heavy', 24000, 100.52);

INSERT INTO eespinoz_Rocket_Ship 
(rocketClass, payload_kg, height_m)
VALUES
('Destroyer', 2000, 100.52);

INSERT INTO eespinoz_Rocket_Ship 
(rocketClass, payload_kg, height_m)
VALUES
('Fighter', 2000, 100.52);

SELECT * FROM DataLog;

-- **************************************************************************************************
-- **************************************************************************************************
-- Testing trigger 2
SELECT * FROM DataLog;

INSERT INTO eespinoz_Rocket_Ship 
(rocketClass, payload_kg, height_m)
VALUES
("Star Destoryer", 24234, 200);

SELECT * FROM DataLog;


-- **************************************************************************************************
-- **************************************************************************************************
-- Testing trigger 3
SELECT * FROM DataLog;

UPDATE eespinoz_Rocket_Ship 
SET height_m = 113.23
WHERE rocketID = 3;

SELECT * FROM DataLog;

-- **************************************************************************************************
-- **************************************************************************************************
-- Testing trigger 4
SELECT * FROM DataLog;

DELETE FROM eespinoz_Rocket_Ship 
WHERE rocketID = 3;

SELECT * FROM DataLog;