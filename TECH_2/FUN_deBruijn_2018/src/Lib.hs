module Lib where
import System.Environment
import Data.List

data Parameters = Parameters {
	n :: Int,
	alpha :: String,
	flag :: String
	} deriving Show

displayHelp :: IO()
displayHelp = do
	putStrLn "USAGE: ./deBruijn n [a] [--check|--unique|--clean]\n"
	putStrLn "\t--check\tcheck if a sequence is a de Bruijn sequence"
	putStrLn "\t--unique\tcheck if 2 sequences are distinct de Bruijn sequences"
	putStrLn "\t--clean\tlist cleani ng"
	putStrLn "\tn\torder of the sequence"
	putStrLn "\ta\talphabet [def: “01”]"
 
getParameters :: [String] -> Parameters
getParameters str_tab =
	if length str_tab == 0 || length str_tab == 1 && head str_tab == "-h"
		then Parameters {n = 0, alpha = "01", flag = "-h"}
		else if length str_tab == 2
			then Parameters { n = strToInt (head str_tab), alpha = "01", flag = (str_tab !! 1) }
		else Parameters { n = strToInt (head str_tab), alpha = (str_tab !! 1), flag = (str_tab !! 2) }

checkSubString :: String -> Int -> [String] -> Bool
checkSubString [] _ substrs = True
checkSubString suite n substrs = do
	let substr = drop 0 . take n $ suite
	if suite /= [] && substr `elem` substrs
		then False
		else checkSubString (drop 1 suite) n (substrs ++ [substr])

checkIfDeBruijin :: Parameters -> String -> String
checkIfDeBruijin param  str = do
	let str2 = drop (n param) str
	if length str /= length (alpha param) ^ (n param)
		then "KO"
	else if checkSubString str2 (n param) [drop 0 . take (n param) $ str]
		then "OK"
		else "KO"

checkIfUnique :: Parameters -> String -> String -> String
checkIfUnique args str1 str2 = do
	if checkIfDeBruijin args str1 == "OK" && checkIfDeBruijin args str2 == "OK"
		then do
			let twostring = str1 ++ str1
			if str2 `isInfixOf` twostring
				then "OK"
				else "KO"
		else "KO"

getAllValidDeBruijin :: Parameters -> IO String
getAllValidDeBruijin args = validDeBruijin ""
	where validDeBruijin contents = do
		line <- getLine
		if line == "END"
			then return contents
		else if checkIfDeBruijin args line == "OK"
			then validDeBruijin (contents ++ line ++ "\n")
				else validDeBruijin (contents)


strToInt :: String -> Int
strToInt str = read str :: Int