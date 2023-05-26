# Rule-based diagnostic system for Hospitals and Medical Facilities

# Define the symptoms and diseases
symptoms = ['Fever', 'Cough', 'Headache', 'Sore throat', 'Dizziness', 'Nausea']
diseases = {
    'Common Cold': ['Fever', 'Cough', 'Headache', 'Sore throat'],
    'Flu': ['Fever', 'Cough', 'Headache'],
    'Strep Throat': ['Fever', 'Sore throat'],
    'Migraine': ['Headache'],
    'Vertigo': ['Dizziness', 'Nausea']
}

# Define the rules for diagnosis
rules = {
    'Rule 1': {
        'category': 'Respiratory',
        'symptoms': ['Fever', 'Cough', 'Sore throat'],
        'disease': 'Common Cold'
    },
    'Rule 2': {
        'category': 'Respiratory',
        'symptoms': ['Fever', 'Cough', 'Headache'],
        'disease': 'Flu'
    },
    'Rule 3': {
        'category': 'Respiratory',
        'symptoms': ['Fever', 'Sore throat'],
        'disease': 'Strep Throat'
    },
    'Rule 4': {
        'category': 'Neurological',
        'symptoms': ['Headache'],
        'disease': 'Migraine'
    },
    'Rule 5': {
        'category': 'Neurological',
        'symptoms': ['Dizziness', 'Nausea'],
        'disease': 'Vertigo'
    }
}

def get_user_input():
    user_symptoms = []
    for symptom in symptoms:
        response = input(f"Do you have {symptom}? (y/n): ")
        if response.lower() == 'y':
            user_symptoms.append(symptom)
    return user_symptoms

def diagnose():
    user_symptoms = get_user_input()
    possible_diseases = []
    disease_categories = []

    for rule_name, rule in rules.items():
        if all(symptom in user_symptoms for symptom in rule['symptoms']):
            possible_diseases.append(rule['disease'])
            disease_categories.append(rule['category'])

    if possible_diseases:
        print("Possible diseases:")
        for i in range(len(possible_diseases)):
            print(f"- {possible_diseases[i]} (Category: {disease_categories[i]})")
    else:
        print("No matching diseases found.")

diagnose()
