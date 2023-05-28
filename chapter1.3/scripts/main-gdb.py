import gdb
import os


class PrintBSTree(gdb.Command):
    def __init__(self) -> None:
        super().__init__("print-bst", gdb.COMMAND_USER)

    def invoke(self, arg, from_tty):
        root = gdb.parse_and_eval(arg)
        graph = 'digraph {'
        nill_index = 0

        q = [root]
        while len(q) > 0:
            node = q.pop(0)
            node_val = str(node["val"])

            if node["left"] != 0:
                graph += "{}->{};".format(node_val,
                                          str(node["left"].dereference()["val"]))
                q.append(node["left"].dereference())
            else:
                graph += "nill{}[shape=point];{}->nill{};".format(
                    nill_index, node_val, nill_index)
                nill_index += 1

            if node["right"] != 0:
                graph += "{}->{};".format(node_val,
                                          str(node["right"].dereference()["val"]))
                q.append(node["right"].dereference())
            else:
                graph += "nill{}[shape=point];{}->nill{};".format(
                    nill_index, node_val, nill_index)
                nill_index += 1

        graph += '}'

        with open("/tmp/output.txt", "w") as f:
            f.write(graph)

        os.system("dot -Tsvg -o /tmp/output.svg /tmp/output.txt")
        os.system("xdg-open /tmp/output.svg")


PrintBSTree()
