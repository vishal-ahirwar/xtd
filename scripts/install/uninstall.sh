#!/usr/bin/env bash

if [ -z ${xtd_version+x} ]; then
  echo "ERROR : Use ./uninstall from root folder"
  exit 1
fi

echo "Uninstall xtd libraries version $xtd_version, copyright Gammasoft, 2022"
echo ""

echo "WARNING : You will unsinstall xtd."
read -p "Press ENTER to continue or CTRL-C to stop..."

manifest_files=("/usr/local/share/xtd/wxwidgets_release_install_manifest.txt" "/usr/local/share/xtd/wxwidgets_debug_install_manifest.txt" "/usr/local/share/xtd/xtd_release_install_manifest.txt" "/usr/local/share/xtd/xtd_debug_install_manifest.txt")

# removing files
for manifest_file in ${manifest_files[@]}; do
  if test -f "$manifest_file"; then
    input="$manifest_file"
    while IFS= read -r line; do
      sudo echo "Removing \"$line\"..."
      sudo rm -f "$line" >/dev/null 2>&1
    done < "$input"
    sudo echo "Removing \"$manifest_file\"..."
    sudo rm -f "$manifest_file" >/dev/null 2>&1
  fi
done

echo ""
echo "xtd is uninstalled."
echo "If you want to use xtd again, you will have to reinstall it."
