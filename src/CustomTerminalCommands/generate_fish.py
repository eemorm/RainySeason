import os

def to_camel_case(s):
    return s[0].upper() + s[1:]

def main():
    fish_name = input("Enter fish name (e.g., Salmon) ").strip()
    class_name = to_camel_case(plant_name)

    difficulty = input("Enter difficulty to catch: ").strip()
    min_weight = input("Enter the minimum weight of the fish: ").strip()
    max_weight = input("Enter the maximum weight of the fish: ").strip()

    print("\nEnter locations to catch in order (e.g., River). Type 'done' to finish.")
    locations = []
    while True:
        location = input("Location: ")
        if stage_input.lower() == 'done':
            break
        parts = stage_input.strip().split()
        locations.append(location)

    output_dir = os.path.join("src", "Classes", "Fishes")
    os.makedirs(output_dir, exist_ok=True)
    file_path = os.path.join(output_dir, f"{class_name}.hpp")

    content = f"""
"""

    with open(file_path, "w") as f:
        f.write(content)

    print(f"\n✅ Generated: {file_path}")

if __name__ == "__main__":
    main()