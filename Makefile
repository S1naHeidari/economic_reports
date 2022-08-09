#!/bin/bash
all:
	gcc -o program main.c initCountryCodes.c getline.c initData.c initDegreePercentages.c initDegreeYearTotal.c initFemaleGraduations.c initYearPercentages.c
