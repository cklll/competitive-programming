# https://www.hackerrank.com/challenges/binary-search-tree-1/problem


SELECT N, IF(P IS NULL, 'Root', IF((SELECT count(*) FROM `BST` t2 WHERE t2.P = t1.N) > 0, 'Inner', 'Leaf')) 
FROM `BST` t1
ORDER by t1.N 
