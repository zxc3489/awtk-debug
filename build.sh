cd src/view_models && ./gen.sh && cd -
python3 ./scripts/update_res.py all x1 mono
scons
