# комменатрий

cmake_minimum_required(VERSION 3.16)


function(my_func PARAM)
    message("my_func(): ${PARAM}")
endfunction()

macro(my_macro)
    message("it is my_macro()")
endmacro()

function(my_parent_scope_func)
    set(PARENT_VAR "WOW, it's parent scope variable!.." PARENT_SCOPE)
endfunction()

#######################
message("###############################################")


message("CMake is the most powerful buildsystem!")  # печатаем на экран


set(VARIABLE "Musya say myaou")
message("VARIABLE is '${VARIABLE}'")
unset(VARIABLE)


message("EMTPY is '${EMPTY}'")


option(USE_ANOTHER_LIBRARY "Do you want to use another library?" OFF)


if(5 LESS 1)
    message("5 less 1!")
endif()
if(4 GREATER 2)
    message("4 greater 2!")
elseif(4 LESS 2)
    message("4 less 2!")
endif()


set(I 1)
while (${I} LESS 3)
    message("pass Airport")
    set(I 4)
endwhile()


foreach(MUSYA Musya want to eat)
    message("foreach CURRENT:\t ${MUSYA}")
endforeach()


foreach(I RANGE 10)
    message("foreach I:\t ${I}")
endforeach()


foreach(NEW_I RANGE 4 15)
    message("foreach NEW_I:\t ${NEW_I}")
endforeach()


foreach(NEW_RANGE_I RANGE 10 40 10)
    message("foreach NEW_RANGE_I:\t ${NEW_RANGE_I}")
endforeach()


my_func(MEGA_MUSYA)
my_macro()


my_parent_scope_func()
message("PARENT_VAR: [${PARENT_VAR}]")


function(custom_function)
    # Вызвать механизм обработки аргументов для текущей функции:
    cmake_parse_arguments(CUSTOM_FUNCTION "LOW;HIGH" "NUMBER" "COLORS" ${ARGV})

    # Напечатает "'LOW' = [TRUE]":
    message("'LOW' = [${CUSTOM_FUNCTION_LOW}]")
    #Напечатает "'HIGH' = [FALSE]":
    message("'HIGH' = [${CUSTOM_FUNCTION_HIGH}]")
    # Напечатает "'NUMBER' = [30]":
    message("'NUMBER' = [${CUSTOM_FUNCTION_NUMBER}]")
    # Напечатает "'COLORS' = [red;green;blue]":
    message("'COLORS' = [${CUSTOM_FUNCTION_COLORS}]")
endfunction()
# Вызвать функцию "custom_function" с произвольными аргументами:
custom_function(LOW NUMBER 30 COLORS red green blue)
message("---")
custom_function(NO_LOW HIGH NUMBER 1 2 3)


message("###############################################")