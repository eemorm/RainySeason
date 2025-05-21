import os

def format_enum_entry(name, day, index, total_stages, plant_name):
    if name.lower() == "dying":
        return f"{name} // a dead {plant_name.lower()} in any stage that has not been watered in the appropriate amount of time"

    ordinals = ["first", "second", "third", "fourth", "fifth", "sixth", "seventh"]

    ordinal = ordinals[index] if index < len(ordinals) else f"stage {index + 1}"

    if index == total_stages - 1:
        comment = f"{ordinal} stage, a fully grown {plant_name.lower()} ready to be harvested"
    else:
        comment = f"{ordinal} stage, a {name.lower()}"

    return f"{name} = {day}, // {comment}" if day else f"{name}, // {comment}"

def to_camel_case(s):
    return s[0].upper() + s[1:]

def main():
    plant_name = input("Enter plant name (e.g., Carrot): ").strip()
    class_name = to_camel_case(plant_name)

    days_to_grow = input("Days to grow: ").strip()
    water_needed = input("Water amount needed: ").strip()

    print("\nEnter growth stages in order (e.g., Seed 0, Sprout 2, Grown 6). Type 'done' to finish. Must have a grown stage.")
    stages = []
    while True:
        stage_input = input("Stage (name day): ")
        if stage_input.lower() == 'done':
            break
        parts = stage_input.strip().split()
        if len(parts) == 1:
            name = parts[0]
            day = ""
        elif len(parts) == 2:
            name, day = parts
        else:
            print("Invalid format. Use: StageName [DayNumber]")
            continue
        stages.append((name, day))

    output_dir = os.path.join("src", "Classes", "Plants")
    os.makedirs(output_dir, exist_ok=True)
    file_path = os.path.join(output_dir, f"{class_name}.hpp")

    stage_enum_entries = ",\n            ".join([
    format_enum_entry(name, day, i, len(stages), class_name)
    for i, (name, day) in enumerate(stages)
])

    stage_initial = stages[0][0]
    grown_stage = stages[-1][0]
    grown_stage_value = stages[-1][1] if stages[-1][1] else "6"

    content = f"""// Custom Includes
#include "Plant.hpp"

// Standard Output
#include <iostream>
#include <string>

class {class_name} : Plant // defines the {class_name} class
{{
    private:
        enum class Stage // defines the growth stages for this particular {class_name}
        {{
            {stage_enum_entries},
            Dying // a dead {class_name} in any stage that has not been watered in the appropriate amount of time
        }};
        Stage stage = Stage::{stage_initial}; // defines the starting stage
    public:
        {class_name}() // constructor
        {{
            setType("{class_name}"); // set type of plant to {class_name}
            setDaysToGrow({days_to_grow}); // amount of days a {class_name} takes to grow
            setWaterAmountNeeded({water_needed}); // amount of water a {class_name} needs to count as fully watered
        }}
        ~{class_name}() {{}} // deconstructor
        // ********************
        Stage getStage() {{ return stage; }}           // getter
        void setStage(Stage s) {{ stage = s; }}        // setter
        // ********************
        void advanceStage() // advance stage if conditions are correct
        {{
            if (stage != Stage::Dying) // check if the plant is not dying
            {{
                int currentStageValue = static_cast<int>(stage);

                if (getGrowthDay() >= currentStageValue + 1) // check if passed next requirement and update stage
                {{
                    stage = static_cast<Stage>(currentStageValue + 1);
                }}
                if (stage == Stage::{grown_stage}) // check if the plant is grown and if the plant can be harvested
                {{
                    setIsHarvestable(true);
                }}
            }}
        }}
}};
"""

    with open(file_path, "w") as f:
        f.write(content)

    print(f"\n✅ Generated: {file_path}")

if __name__ == "__main__":
    main()