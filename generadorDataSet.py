import random
import string
import csv

# Genera una cadena aleatoria de la longitud especificada.
def generate_random_string(length):
    return ''.join(random.choices(string.ascii_lowercase, k=length))

# Genera el dataset Palabra vacía vs palabra de tamaño n.
def generate_empty_vs_n(file_name, lengths):
    with open(file_name, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["tamanio_cadena1", "tamanio_cadena2", "cadena1", "cadena2"])
        for length in lengths:
            for _ in range(3):
                writer.writerow([0, length, "", generate_random_string(length)])

# Genera el dataset Cadenas aleatorias de tamaño n × m.
def generate_random_nxm(file_name, lengths):
    with open(file_name, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["tamanio_cadena1", "tamanio_cadena2", "cadena1", "cadena2"])
        for length in lengths:
            for _ in range(3):
                writer.writerow([length, length, generate_random_string(length), generate_random_string(length)])

# Genera el dataset Cadenas con transposiciones.
def generate_transpositions(file_name, lengths):
    with open(file_name, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["tamanio_cadena1", "tamanio_cadena2", "cadena1", "cadena2"])
        for length in lengths:
            for _ in range(3):
                s1 = generate_random_string(length)
                s2 = list(s1)
                if length > 1:
                    for i in range(0, length - 1, 2):
                        s2[i], s2[i + 1] = s2[i + 1], s2[i]  # Transposición
                writer.writerow([length, length, s1, ''.join(s2)])


# Genera el dataset Cadenas con 80 % de similitud.
def generate_high_similarity(file_name, lengths):
    with open(file_name, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["tamanio_cadena1", "tamanio_cadena2", "cadena1", "cadena2"])
        for length in lengths:
            for _ in range(3):
                s1 = generate_random_string(length)
                s2 = list(s1)
                changes = int(0.2 * length) # Cambios en el 20% de los caracteres
                for _ in range(changes):
                    idx = random.randint(0, length - 1)
                    s2[idx] = random.choice(string.ascii_lowercase)  # Cambia un carácter
                writer.writerow([length, length, s1, ''.join(s2)])

# Genera el dataset Cadenas con una subcadena común del 50 %.
def generate_common_substring(file_name, lengths):
    with open(file_name, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["tamanio_cadena1", "tamanio_cadena2", "cadena1", "cadena2"])
        for length in lengths:
            for _ in range(3):
                # Generar la subcadena común
                common_substring = generate_random_string(length // 2)
                
                # Generar las partes únicas
                unique_part1 = generate_random_string(length - len(common_substring))
                unique_part2 = generate_random_string(length - len(common_substring))
                
                # Construir las cadenas con la subcadena común
                s1 = unique_part1 + common_substring
                s2 = common_substring + unique_part2
                
                writer.writerow([length, length, s1, s2])

# Longitudes de cadenas para los datasets
lengths_comun = [3, 6, 10]

# Generación de los datasets en la carpeta DataSet_comun
generate_empty_vs_n("DataSet_comun/empty_vs_n.csv", lengths_comun)
generate_random_nxm("DataSet_comun/random_nxm.csv", lengths_comun)
generate_transpositions("DataSet_comun/transpositions.csv", lengths_comun)
generate_high_similarity("DataSet_comun/high_similarity.csv", lengths_comun)
generate_common_substring("DataSet_comun/common_substring.csv", lengths_comun)

lengths_dp = [2**5, 2**6, 2**7, 2**8, 2**9, 2**10, 2**11, 2**12]
# Generación del dataset en la carpeta DataSet_dp
generate_random_nxm("DataSet_dp/random_nxm.csv", lengths_dp)

print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
print("Archivos DataSets Creados :)")
print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%")