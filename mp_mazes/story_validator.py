from sys import argv, exit
import os
from collections import defaultdict

class colors:
	BLUE = '\033[94m'
	GREEN = '\033[92m'
	RED = '\033[91m'
	ENDC = '\033[0m'

class results:
	PASS = 2
	WARN = 1
	ERR = 0

def colored(msg, color):
	return color + msg + colors.ENDC

def exit_usage():
	print(colored(f'Usage: \tpython3 {argv[0]} <path to story_data directory>', colors.RED))
	exit(1)

def print_info(msg):
	print(msg)

def print_error(msg):
	print(colored(msg, colors.RED))

def exit_error(msg):
	print_error(msg)
	print_error('Exiting.')
	exit(1)

if __name__ == '__main__':
	if len(argv) != 2 or not os.path.isdir(argv[1]):
		exit_usage()

	result = results.PASS

	file_filter = lambda f: os.path.isfile(f'{argv[1]}/{f}') and f[-3:] == '.md'
	waf_filter = lambda f: f[0:4] == 'waf-'
	strip_md_mapper = lambda f: f[0:-3]
	md_files = list(map(strip_md_mapper, filter(file_filter, os.listdir(argv[1]))))
	if list(filter(waf_filter, md_files)):
		exit_error('ERR: You must delete waf-*.md files – write your own story! :)')
	
	print_info(f'Found {len(md_files)} .md files in {argv[1]}.')

	edges_dict = {}
	stories = {}

	for md_filename in md_files:
		with open(f'{argv[1]}/{md_filename}.md', 'r') as file:
			lines = file.readlines()

			i = 0
			while i < len(lines) and lines[i][0:2] != '# ':
				if lines[i][0] == '#':
					print_error(f'WARN: A line in {md_filename}.md begins with a # that is not followed by a space. This is probably an error.')
					result = min(result, results.WARN)
				i += 1

			if i == 0:
				exit_error(f'ERR: Empty file: {md_filename}')

			story_lines = filter(lambda l: len(l) > 0, map(lambda l: l.lstrip().rstrip(), lines[0:i]))
			story = '\n'.join(story_lines)
			
			edges = []
			while i < len(lines):
				dest = lines[i][2:].rstrip()
				j = i+1
				while j < len(lines) and lines[j][0:2] != '# ':
					if lines[j][0] == '#':
						print_error(f'WARN: A line in {md_filename}.md begins with a # that is not followed by a space. This is probably an error.')
						result = min(result, results.WARN)
					j += 1
				label_lines = filter(lambda l: len(l) > 0, map(lambda l: l.lstrip().rstrip(), lines[i+1:j]))
				label = '\n'.join(label_lines)
				edges.append((dest, label))
				i = j

			edges_dict[md_filename] = edges
			stories[md_filename] = story

	incoming_edges = defaultdict(list)
	has_end_node = False
	has_3_edge_node = False

	for md_filename, edges in edges_dict.items():
		for dest, _ in edges:
			incoming_edges[dest].append(md_filename)
			if dest not in edges_dict:
				exit_error(f'ERR: File {md_filename} has edge referring to non-existent file {dest}.md')

		if len(edges) == 0:
			has_end_node = True
		elif len(edges) >= 3:
			has_3_edge_node = True

		if len(edges) > 10:
			exit_error(f'ERR: File {md_filename} has more than 10 choices (outgoing edges)! Has: {len(edges)} choices')

	print('\nYour graph was parsed as follows:\n')

	for node, edges in edges_dict.items():
		print(colored(node, colors.BLUE))
		print(stories[node])
		for edge, story in edges:
			print(colored(f'\t==> {edge}', colors.BLUE) + f': {story}')
		print()

	if not has_end_node:
		print_error('ERR: At least one narrative must be the ending of the story (an ending vertex will have no outbound edges).')
		result = min(result, results.ERR)

	if not has_3_edge_node:
		print_error('ERR: At least one narrative must have at least 3 choices.')
		result = min(result, results.ERR)

	num_start_nodes = 0
	for node in edges_dict.keys():
		if len(incoming_edges[node]) == 0:
			num_start_nodes += 1

	if num_start_nodes == 0:
		print_error('ERR: Exactly one narrative must be the beginning of the story (one vertex must have no incoming edges). No beginning node found.')
		result = min(result, results.ERR)
	elif num_start_nodes > 1:
		print_error(f'ERR: Exactly one narrative must be the beginning of the story (one vertex must have no incoming edges). {num_start_nodes} beginning nodes found.')
		result = min(result, results.ERR)

	num_total_nodes = len(edges_dict)
	if num_total_nodes < 8:
		print_error(f'ERR: Your interactive story must have at least 8 narratives. Actual number of narratives: {num_total_nodes}')
		result = min(result, results.ERR)

	num_total_edges = sum(map(len, edges_dict.values()))
	if num_total_edges < 13:
		print_error(f'ERR: Your interactive story must have at least 13 choices. Actual number of choices: {num_total_edges}')
		result = min(result, results.ERR)

	if result == results.PASS:
		print_info(colored('Validation completed with no errors or warnings.', colors.GREEN))
	elif result == results.WARN:
		print_error('Validation completed with warnings.')
	elif result == results.ERR:
		print_error('Validation completed with errors.')
	
