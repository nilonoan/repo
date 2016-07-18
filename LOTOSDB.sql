CLEAR SCREEN;
DECLARE 
  V_DESCR ALT_QUERY.DESCR%TYPE := 'Automation purposes';
  V_NAME ALT_QUERY.NAME%TYPE := 'Automation_Test';
  V_QUERY ALT_QUERY.QUERY%TYPE := 'Test';
  V_CATEGORY_FK ALT_QUERY.CATEGORY_FK%TYPE := 121;
  V_EXISTS NUMBER(1) := 0;
  V_AFFECTED_ROWS NUMBER(3) := -1;
BEGIN
  BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE TEMP_RETURN';
  EXCEPTION
    WHEN OTHERS THEN
      IF SQLCODE != -942 THEN
        RAISE;
      END IF;
  END;

  EXECUTE IMMEDIATE 'CREATE GLOBAL TEMPORARY TABLE TEMP_RETURN(AFFECTED_ROWS NUMBER(3))';

  SELECT CASE WHEN EXISTS(
          SELECT 1 FROM ALT_QUERY
          WHERE 
            DESCR = V_DESCR 
            AND NAME = V_NAME 
            AND QUERY = V_QUERY 
            AND CATEGORY_FK = V_CATEGORY_FK
          )
          THEN 1 
          ELSE 0    
        END INTO V_EXISTS
  FROM DUAL;
  
  IF V_EXISTS = 1 THEN   
    DELETE FROM ALT_RULE     
    WHERE 
      ALT_QUERY_FK IN (
                        SELECT ID FROM ALT_QUERY                                
                        WHERE
                          DESCR = V_DESCR 
                          AND NAME = V_NAME 
                          AND QUERY = V_QUERY
                          AND CATEGORY_FK = V_CATEGORY_FK                        
                      );
    
    DELETE FROM ALT_QUERY      
    WHERE
      DESCR = V_DESCR 
      AND NAME = V_NAME 
      AND QUERY = V_QUERY
      AND CATEGORY_FK = V_CATEGORY_FK;
    
    V_AFFECTED_ROWS := SQL%ROWCOUNT;  
    
    ROLLBACK;
  END IF;

  INSERT INTO TEMP_RETURN(AFFECTED_ROWS)
  VALUES(V_AFFECTED_ROWS);
END; 

CLEAR SCREEN;
SELECT * FROM TEMP_RETURN;
DROP TABLE TEMP_RETURN;
