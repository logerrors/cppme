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
