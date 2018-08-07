# https://www.hackerrank.com/challenges/the-company/problem

SELECT C.`company_code`, C.founder,
COUNT(DISTINCT LM.lead_manager_code),
COUNT(DISTINCT SM.senior_manager_code),
COUNT(DISTINCT M.manager_code),
COUNT(DISTINCT E.employee_code)
FROM `Company` C, `Lead_Manager` LM, `Senior_Manager` SM, `Manager` M, `Employee` E
WHERE C.company_code = LM.company_code AND
C.company_code = SM.company_code AND
C.company_code = M.company_code AND
C.company_code = E.company_code
GROUP BY C.`company_code`, C.`founder`
ORDER BY C.`company_code` ASC
;
