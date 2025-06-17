#!/bin/bash

make


echo "Test 1"
./Sed_is_for_losers ./tests/test_01 bonjour salut
diff tests/test_01.replace tests/expected/expected_01 && echo "✅ OK" || echo "❌ FAILED"


echo "Test 2"
./Sed_is_for_losers ./tests/test_02_empty a b
diff tests/test_02_empty.replace tests/expected/expected_02 && echo "✅ OK" || echo "❌ FAILED"


echo "Test 3"
./Sed_is_for_losers ./tests/test_03_no_s1 xyz abc
diff tests/test_03_no_s1.replace tests/expected/expected_03 && echo "✅ OK" || echo "❌ FAILED"


echo "Test 4"
./Sed_is_for_losers ./tests/test_04_full_match x Y
diff tests/test_04_full_match.replace tests/expected/expected_04 && echo "✅ OK" || echo "❌ FAILED"


echo "Test 5"
./Sed_is_for_losers ./tests/test_05_s1_equal_s2 abc abc
diff tests/test_05_s1_equal_s2.replace tests/expected/expected_05 && echo "✅ OK" || echo "❌ FAILED"


echo "Test 6"
./Sed_is_for_losers ./tests/test_06_empty_s1 "" b
if [ ! -f tests/test_06_empty_s1.replace ]; then
    echo "✅ OK (aucun fichier cree)"
else
    echo "❌ FAILED (le fichier .replace ne devrait pas exister)"
    rm -f tests/test_06_empty_s1.replace
fi



rm -f tests/*.replace
make fclean