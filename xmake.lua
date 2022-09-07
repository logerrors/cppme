add_rules("mode.debug", "mode.release")

set_languages("c++17")

set_optimize("none")

function define_target(target_name) 
    target(target_name)
        set_kind("binary")
        -- add_packages("icecream")
        add_files('src/'..target_name..'.cpp')
end


define_target("basic_type")
define_target("assign")
define_target("getchar_putchar")
define_target("switch")
define_target("goto")
define_target("array")
define_target("function")
define_target("var")
define_target("scope")
define_target("macro")
define_target("ptr")
define_target("char")
define_target("struct")
define_target("union")
define_target("enum")
define_target("typedef")
define_target("bit")
define_target("file")
define_target("struct_align")
