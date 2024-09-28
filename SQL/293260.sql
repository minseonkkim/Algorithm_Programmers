SELECT COUNT(*) AS FISH_COUNT, CAST(SUBSTRING(TIME, 6, 2) AS UNSIGNED) AS MONTH
FROM FISH_INFO
GROUP BY MONTH
ORDER BY MONTH;
